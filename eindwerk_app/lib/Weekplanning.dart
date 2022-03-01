import 'dart:ui';
import 'package:eindwerk_app/mobile_weekplanning.dart';
import 'package:eindwerk_app/responsive.dart';
import 'package:eindwerk_app/tablet_weekplanning.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:eindwerk_app/homepage.dart';
import 'package:responsive_framework/responsive_framework.dart';

class Weekplanning extends StatefulWidget {
  @override
  _WeekplanningState createState() => _WeekplanningState();
}

class _WeekplanningState extends State<Weekplanning> {
  void click() {
    Navigator.push(
        context, MaterialPageRoute(builder: (context) => Myhomepage()));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        bottomNavigationBar: BottomAppBar(
          color: Colors.lightBlue,
          child: Row(
            children: [
              IconButton(
                icon: Icon(Icons.arrow_back_sharp),
                onPressed: () => Navigator.of(context).pop(),
                splashColor: Colors.blue,
              ),
              Spacer(),
              IconButton(
                icon: Icon(Icons.menu),
                onPressed: () {},
                splashColor: Colors.blue,
              ),
            ],
          ),
        ),
        floatingActionButton: FloatingActionButton(
          child: Icon(
            Icons.home_outlined,
            color: Colors.black,
          ),
          onPressed: this.click,
          splashColor: Colors.blue,
        ),
        floatingActionButtonLocation: FloatingActionButtonLocation.centerDocked,
        body: responsivelayout(
          tabletbody: MytabletWeekplanning(),
          mobilebody: MymobileWeekplanning(),
        ));
  }
}
