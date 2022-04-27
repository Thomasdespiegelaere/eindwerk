import 'package:flutter/material.dart';
import 'package:eindwerk_app/Weekplanning.dart';
import 'package:flutter/services.dart';
import 'package:eindwerk_app/gegevens.dart';

class Mymobilehome extends StatefulWidget {
  //de homepagina class
  @override
  _MymobilehomeState createState() => _MymobilehomeState(); //creërt de pagina
}

class _MymobilehomeState extends State<Mymobilehome> {
  //de pagina zelf
  void click() {
    //de functie wanneer de knop van weekplanning wordt ingedrukt
    Navigator.push(
        //verplaats de weekplanning pagina naar de bovenkant van de stapel met pagina's
        context,
        MaterialPageRoute(builder: (context) => Weekplanning()));
  }

  void geg() {
    //de functie wanneer de knop van weekplanning wordt ingedrukt
    Navigator.push(
        //verplaats de weekplanning pagina naar de bovenkant van de stapel met pagina's
        context,
        MaterialPageRoute(builder: (context) => Mygegevenspage()));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: Container(
      child: Column(
        //dit is de layout van de app zelf
        mainAxisAlignment: MainAxisAlignment.spaceEvenly,
        children: [
          //Image.asset('assets/images/smart-home-automation-2.jpg'),
          Column(
            //een rij met twee knoppen erin om naar de pagina's te gaan
            //spacing: 30,
            children: [
              SizedBox(
                width: 30,
                height: 50,
              ),
              SizedBox(
                width: 200,
                height: 150,
                child: ElevatedButton.icon(
                  //knop om naar de weekplanning te gaan
                  icon: Icon(
                    Icons.calendar_today_rounded,
                    color: Color.fromARGB(255, 2, 195, 221),
                    size: 40,
                  ),
                  label: Text(
                    "Weekplanning",
                    style: TextStyle(
                        color: Color.fromARGB(255, 2, 195, 221), fontSize: 17),
                  ),
                  onPressed: this.click,
                  style: ElevatedButton.styleFrom(
                      primary: Color.fromRGBO(30, 30, 30, 1),
                      elevation: 10,
                      shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(20))),
                ),
              ),
              SizedBox(
                width: 30,
                height: 50,
              ),
              SizedBox(
                width: 200,
                height: 150,
                child: ElevatedButton.icon(
                  //knop om naar de gegevens te gaan
                  icon: Icon(
                    Icons.query_stats,
                    color: Color.fromARGB(255, 2, 195, 221),
                    size: 40,
                  ),
                  label: Text(
                    "Gegevens",
                    style: TextStyle(
                        color: Color.fromARGB(255, 2, 195, 221), fontSize: 17),
                  ),
                  onPressed: this.geg,
                  style: ElevatedButton.styleFrom(
                      primary: Color.fromRGBO(30, 30, 30, 1),
                      elevation: 10,
                      shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(20))),
                ),
              ),
              SizedBox(
                width: 760,
                height: 100,
              )
            ],
          ),
        ],
      ),
    ));
  }
}
