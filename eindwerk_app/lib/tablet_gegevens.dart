import 'package:flutter/material.dart';
import 'package:eindwerk_app/Weekplanning.dart';
import 'package:flutter/services.dart';

class Mytabletgegevens extends StatefulWidget {
  //de homepagina class
  @override
  _MytabletgegevensState createState() =>
      _MytabletgegevensState(); //creërt de pagina
}

class _MytabletgegevensState extends State<Mytabletgegevens> {
  //de pagina zelf
  void click() {
    //de functie wanneer de knop van weekplanning wordt ingedrukt
    Navigator.push(
        //verplaats de weekplanning pagina naar de bovenkant van de stapel met pagina's
        context,
        MaterialPageRoute(builder: (context) => Weekplanning()));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: Container(
      child: Text(
        "tablet",
        style: TextStyle(color: Colors.white),
      ),
    ));
  }
}
