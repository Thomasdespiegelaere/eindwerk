import 'dart:async';
import 'dart:ffi';
import 'package:flutter/material.dart';
import 'package:eindwerk_app/Weekplanning.dart';
import 'package:flutter/services.dart';
import 'package:syncfusion_flutter_charts/charts.dart';
import 'package:syncfusion_flutter_charts/sparkcharts.dart';
import 'dart:math' as math;
import 'package:firebase_database/firebase_database.dart';

class Mytabletgegevens extends StatefulWidget {
  //de homepagina class
  @override
  _MytabletgegevensState createState() =>
      _MytabletgegevensState(); //creërt de pagina
}

class _MytabletgegevensState extends State<Mytabletgegevens> {
  Timer timer;
  ChartSeriesController _chartSeriesController;
  final database = FirebaseDatabase.instance.ref();
  //de pagina zelf

  String X0 = "";
  String Y0 = "";
  String Y1 = "";
  bool list = true;
  double time = 0;

  void _updateDataSource(Timer timer) {
    final root = database.child('/');
    root.child('Data/uur/').get().then((DataSnapshot snapshot) {
      if (mounted) {
        setState(() {
          X0 = snapshot.value;
        });
      }
    });
    root.child('Data/zon/').get().then((DataSnapshot snapshot) {
      if (mounted) {
        setState(() {
          Y0 = snapshot.value;
        });
      }
    });
    root.child('Data/batt/').get().then((DataSnapshot snapshot) {
      if (mounted) {
        setState(() {
          Y1 = snapshot.value;
        });
      }
    });
    /*List<int> list1 = [];
    for (int i = 0; i < double.parse(X0);) {
      list1.add(i);
      i++;
    }*/
    chartData.add(ChartSampleData(
        time++ /*double.parse(X0)*/, double.parse(Y0), double.parse(Y1)));
    /*for (int i = 0; i < double.parse(X0);) {
      chartData.removeAt(i);
      i++;
    }*/
    chartData.removeAt(0);
    _chartSeriesController.updateDataSource(
      removedDataIndex: 0, //list1,
      addedDataIndex: chartData.length - 1,
    );
  }

  final List<ChartSampleData> chartData = <ChartSampleData>[
    ChartSampleData(0, null, null),
    ChartSampleData(1, null, null),
    ChartSampleData(2, null, null),
    ChartSampleData(3, null, null),
    ChartSampleData(4, null, null),
    ChartSampleData(5, null, null),
    ChartSampleData(6, null, null),
    ChartSampleData(7, null, null),
    ChartSampleData(8, null, null),
    ChartSampleData(9, null, null),
    ChartSampleData(10, null, null),
    ChartSampleData(11, null, null),
    ChartSampleData(12, null, null),
    ChartSampleData(13, null, null),
    ChartSampleData(14, null, null),
    ChartSampleData(15, null, null),
    ChartSampleData(16, null, null),
    ChartSampleData(17, null, null),
    ChartSampleData(18, null, null),
    ChartSampleData(19, null, null),
    ChartSampleData(20, null, null),
    ChartSampleData(21, null, null),
    ChartSampleData(22, null, null),
    ChartSampleData(23, null, null),
    ChartSampleData(24, null, null),
  ];

  @override
  void dispose() {
    super.dispose();
    timer?.cancel();
  }

  Widget build(BuildContext context) {
    timer = Timer.periodic(const Duration(seconds: 10), _updateDataSource);
    return Scaffold(
      body: Center(
        child: Container(
          height: 500,
          width: 700,
          child: SfCartesianChart(
              legend: Legend(
                  isVisible: true,
                  textStyle:
                      TextStyle(color: Color.fromARGB(255, 160, 159, 159))),
              series: [
                LineSeries<ChartSampleData, num>(
                    name: 'zon',
                    onRendererCreated: (ChartSeriesController controller) {
                      _chartSeriesController = controller;
                    },
                    dataSource: chartData,
                    xValueMapper: (ChartSampleData data, _) => data.x,
                    yValueMapper: (ChartSampleData data, _) => data.y,
                    isVisible: true),
                LineSeries<ChartSampleData, num>(
                    name: 'batterij',
                    onRendererCreated: (ChartSeriesController controller) {
                      _chartSeriesController = controller;
                    },
                    dataSource: chartData,
                    xValueMapper: (ChartSampleData data, _) => data.x,
                    yValueMapper: (ChartSampleData data, _) => data.y1,
                    color: Colors.red,
                    isVisible: true)
              ],
              primaryXAxis: NumericAxis(
                interval: 2,
                isVisible: false,
              ),
              primaryYAxis: NumericAxis(
                  isVisible: true, interval: 1, minimum: 0, maximum: 14.0)),
        ),
      ),
    );
  }
}

class ChartSampleData {
  ChartSampleData(this.x, this.y, this.y1);
  final double x;
  final double y;
  final double y1;

  static void add(ChartSampleData chartSampleData) {}
}
