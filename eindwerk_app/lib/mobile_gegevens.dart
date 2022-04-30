import 'dart:async';
import 'package:flutter/material.dart';
import 'package:eindwerk_app/Weekplanning.dart';
import 'package:flutter/services.dart';
import 'package:syncfusion_flutter_charts/charts.dart';
import 'package:syncfusion_flutter_charts/sparkcharts.dart';
import 'dart:math' as math;

class Mymobilegegevens extends StatefulWidget {
  //de homepagina class
  @override
  _MymobilegegevensState createState() =>
      _MymobilegegevensState(); //creërt de pagina
}

class _MymobilegegevensState extends State<Mymobilegegevens> {
  Timer timer;
  ChartSeriesController _chartSeriesController;
  //de pagina zelf
  void click() {
    //de functie wanneer de knop van weekplanning wordt ingedrukt
    Navigator.push(
        //verplaats de weekplanning pagina naar de bovenkant van de stapel met pagina's
        context,
        MaterialPageRoute(builder: (context) => Weekplanning()));
  }

  int time = 25;
  void _updateDataSource(Timer timer) {
    chartData.add(ChartSampleData(time++, math.Random().nextInt(80)));
    chartData.removeAt(0);
    _chartSeriesController.updateDataSource(
        addedDataIndex: chartData.length - 1, removedDataIndex: 0);
  }

  List<ChartSampleData> chartData = <ChartSampleData>[
    ChartSampleData(0, 10),
    ChartSampleData(1, 13),
    ChartSampleData(2, 80),
    ChartSampleData(3, 30),
    ChartSampleData(4, 72),
    ChartSampleData(5, 30),
    ChartSampleData(6, 13),
    ChartSampleData(7, 80),
    ChartSampleData(8, 30),
    ChartSampleData(9, 72),
    ChartSampleData(10, 30),
    ChartSampleData(11, 13),
    ChartSampleData(12, 80),
    ChartSampleData(13, 30),
    ChartSampleData(14, 72),
    ChartSampleData(15, 30),
    ChartSampleData(16, 13),
    ChartSampleData(17, 80),
    ChartSampleData(18, 30),
    ChartSampleData(19, 72),
    ChartSampleData(20, 30),
    ChartSampleData(21, 13),
    ChartSampleData(22, 80),
    ChartSampleData(23, 30),
    ChartSampleData(24, 72),
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
  ChartSampleData(this.x, this.y);
  final int x;
  final int y;

  static void add(ChartSampleData chartSampleData) {}
}
