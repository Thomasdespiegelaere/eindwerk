import 'package:flutter/material.dart';
import 'package:eindwerk_app/Weekplanning.dart';
import 'package:flutter/services.dart';
import 'package:syncfusion_flutter_charts/charts.dart';
import 'package:syncfusion_flutter_charts/sparkcharts.dart';

class Mymobilegegevens extends StatefulWidget {
  //de homepagina class
  @override
  _MymobilegegevensState createState() =>
      _MymobilegegevensState(); //creërt de pagina
}

class _MymobilegegevensState extends State<Mymobilegegevens> {
  //de pagina zelf
  void click() {
    //de functie wanneer de knop van weekplanning wordt ingedrukt
    Navigator.push(
        //verplaats de weekplanning pagina naar de bovenkant van de stapel met pagina's
        context,
        MaterialPageRoute(builder: (context) => Weekplanning()));
  }

  final List<ChartSampleData> chartData = <ChartSampleData>[
    ChartSampleData("maa", 30),
    ChartSampleData("din", 13),
    ChartSampleData("woe", 80),
    ChartSampleData("don", 30),
    ChartSampleData("vrij", 72)
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Container(
            height: 500,
            width: 500,
            child: SfCartesianChart(
                // Initialize category axis
                primaryXAxis: CategoryAxis(),
                series: <ChartSeries>[
                  // Initialize line series
                  LineSeries<ChartSampleData, String>(
                      dataSource: chartData,
                      xValueMapper: (ChartSampleData data, _) => data.x,
                      yValueMapper: (ChartSampleData data, _) => data.y)
                ])),
      ),
    );
  }
}

class ChartSampleData {
  ChartSampleData(this.x, this.y);
  final String x;
  final double y;

  static void add(ChartSampleData chartSampleData) {}
}

List<ChartSampleData> _getChartData() {
  ChartSampleData.add(ChartSampleData("maa", 10));
  ChartSampleData.add(ChartSampleData("din", 10));
  ChartSampleData.add(ChartSampleData("woe", 10));
  ChartSampleData.add(ChartSampleData("don", 10));
  ChartSampleData.add(ChartSampleData("vrij", 10));
  List<ChartSampleData> chartData;
  return chartData;
}
