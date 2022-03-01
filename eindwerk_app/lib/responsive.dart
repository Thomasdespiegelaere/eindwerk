import 'package:flutter/material.dart';

class responsivelayout extends StatelessWidget {
  final Widget mobilebody;
  final Widget tabletbody;

  responsivelayout({this.mobilebody, this.tabletbody});

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(builder: (context, constraints) {
      if (constraints.maxWidth < 600) {
        return mobilebody;
      } else {
        return tabletbody;
      }
    });
  }
}
