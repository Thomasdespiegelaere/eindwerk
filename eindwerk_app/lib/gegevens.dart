import 'package:eindwerk_app/Weekplanning.dart';
import 'package:eindwerk_app/mobile_home.dart';
import 'package:eindwerk_app/responsive.dart';
import 'package:eindwerk_app/tablet_home.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'mobile_gegevens.dart';
import 'tablet_gegevens.dart';
import 'homepage.dart';
import 'package:shared_preferences/shared_preferences.dart';

class Mygegevenspage extends StatefulWidget {
  //de homepagina class
  @override
  _MygegevenspageState createState() =>
      _MygegevenspageState(); //creërt de pagina
}

class _MygegevenspageState extends State<Mygegevenspage> {
  void click() {
    Navigator.push(
        context, MaterialPageRoute(builder: (context) => Myhomepage()));
  }

  final prefs = SharedPreferences.getInstance();
  bool _giveVerse = true;
  bool _giveVerse1 = true;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      bottomNavigationBar: BottomAppBar(
        //dit is de navigatiebalk onder in de app
        color: Colors.lightBlue,
        child: Row(
          children: [
            PopupMenuButton(
                icon: const Icon(Icons.more_vert),
                itemBuilder: (context) {
                  return [
                    PopupMenuItem<int>(
                        value: 0,
                        child: Row(
                          children: [
                            Text("Zon"),
                            Switch(
                              value: _giveVerse,
                              onChanged: (bool newValue) {
                                setState(() {
                                  _giveVerse = newValue;
                                  prefs.setbool('vis', newValue);
                                });
                              },
                            )
                          ],
                        )),
                    PopupMenuItem<int>(
                      value: 1,
                      child: Row(
                        children: [
                          Text("batt"),
                          Switch(
                            value: _giveVerse,
                            onChanged: (bool newValue) {
                              setState(() {
                                _giveVerse1 = newValue;
                              });
                            },
                          )
                        ],
                      ),
                    ),
                    PopupMenuItem<int>(
                        value: 2,
                        child: Row(
                          children: [
                            Text("yo"),
                            Switch(value: true, onChanged: null)
                          ],
                        )),
                  ];
                },
                onSelected: (value) {
                  if (value == 0) {
                    setState(() {});
                  } else if (value == 1) {
                    setState(() {});
                  } else if (value == 2) {
                    setState(() {});
                  }
                }),
            Spacer(), //plaats tussen de knoppen optie en menu
            IconButton(
              //de menu knop in de navigatiebalk
              icon: Icon(
                Icons.home_outlined,
                size: 35,
              ),
              onPressed: this.click,
              splashColor: Colors.blue,
            ),
            Spacer(),
            IconButton(
              //de menu knop in de navigatiebalk
              icon: Icon(Icons.menu),
              onPressed: () {},
              splashColor: Colors.blue,
            ),
          ],
        ),
      ),
      body: responsivelayout(
        tabletbody: Mytabletgegevens(),
        mobilebody: Mymobilegegevens(),
      ),
    );
  }
}
