import 'dart:async';
import 'dart:ffi';
import 'package:flutter/material.dart';
import 'package:eindwerk_app/Weekplanning.dart';
import 'package:flutter/services.dart';
import 'package:syncfusion_flutter_charts/charts.dart';
import 'package:syncfusion_flutter_charts/sparkcharts.dart';
import 'dart:math' as math;
import 'package:firebase_database/firebase_database.dart';

class Mymobilegegevens extends StatefulWidget {
  //de homepagina class
  @override
  _MymobilegegevensState createState() =>
      _MymobilegegevensState(); //creërt de pagina
}

class _MymobilegegevensState extends State<Mymobilegegevens> {
  Timer timer;
  ChartSeriesController _chartSeriesController;
  final database = FirebaseDatabase.instance.ref();
  //de pagina zelf

  bool vis = true;
  bool vis1 = true;
  int time = 25;
  String z = "";
  void _updateDataSource(Timer timer) {
    final root = database.child('/');
    root.child('Data/zon/').get().then((DataSnapshot snapshot) {
      setState(() {
        z = snapshot.value;
      });
    });
    chartData.add(ChartSampleData(
        time++, math.Random().nextInt(80), math.Random().nextInt(80)));
    chartData.removeAt(0);
    _chartSeriesController.updateDataSource(
        addedDataIndex: chartData.length - 1, removedDataIndex: 0);
  }

  List<ChartSampleData> chartData = <ChartSampleData>[
    ChartSampleData(0, 10, 5),
    ChartSampleData(1, 13, 7),
    ChartSampleData(2, 80, 8),
    ChartSampleData(3, 30, 10),
    ChartSampleData(4, 72, 11),
    ChartSampleData(5, 30, 12),
    ChartSampleData(6, 13, 11),
    ChartSampleData(7, 80, 55),
    ChartSampleData(8, 30, 70),
    ChartSampleData(9, 72, 60),
    ChartSampleData(10, 30, 55),
    ChartSampleData(11, 13, 23),
    ChartSampleData(12, 80, 17),
    ChartSampleData(13, 30, 12),
    ChartSampleData(14, 72, 30),
    ChartSampleData(15, 30, 66),
    ChartSampleData(16, 13, 40),
    ChartSampleData(17, 80, 55),
    ChartSampleData(18, 30, 10),
    ChartSampleData(19, 72, 11),
    ChartSampleData(20, 30, 77),
    ChartSampleData(21, 13, 5),
    ChartSampleData(22, 80, 50),
    ChartSampleData(23, 30, 25),
    ChartSampleData(24, 72, 63),
  ];

  @override
  void dispose() {
    super.dispose();
    timer?.cancel();
  }

  Widget build(BuildContext context) {
    timer = Timer.periodic(const Duration(seconds: 1), _updateDataSource);
    return Scaffold(
      body: Center(
        child: Container(
          height: 500,
          width: 500,
          child: SfCartesianChart(
              series: [
                LineSeries<ChartSampleData, int>(
                  onRendererCreated: (ChartSeriesController controller) {
                    _chartSeriesController = controller;
                  },
                  dataSource: chartData,
                  xValueMapper: (ChartSampleData data, _) => data.x,
                  yValueMapper: (ChartSampleData data, _) => data.y,
                  isVisible: vis,
                ),
                LineSeries<ChartSampleData, int>(
                  onRendererCreated: (ChartSeriesController controller) {
                    _chartSeriesController = controller;
                  },
                  dataSource: chartData,
                  xValueMapper: (ChartSampleData data, _) => data.x,
                  yValueMapper: (ChartSampleData data, _) => data.y1,
                  color: Colors.red,
                  isVisible: vis1,
                )
              ],
              primaryXAxis: NumericAxis(
                interval: 2,
              )),
        ),
      ),
    );
  }
}

class ChartSampleData {
  ChartSampleData(this.x, this.y, this.y1);
  final int x;
  final int y;
  final int y1;

  static void add(ChartSampleData chartSampleData) {}
}
