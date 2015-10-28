import com.sun.org.apache.xml.internal.dtm.DTMAxisIterator;

import java.util.*;


/**
 * Created by IMAN on 10/22/2015.
 */

public class Main {
    public static class Record implements Comparable<Record>{
        String date, name, time;

        public Record(String date, String name, String time) {
            this.date = date;
            this.name = name;
            this.time = time;
        }

        @Override
        public String toString() {
            return date + " ||| " + time + " ||| " + name;
        }

        @Override
        public int compareTo(Record o) {
            return toString().compareTo(o.toString());
        }
    }

    public static class MyTime implements Comparable<MyTime>{
        int hour, min, sec;

        public MyTime(int hour, int min, int sec) {
            this.hour = hour;
            this.min = min;
            this.sec = sec;
            selfCorrect();
        }

        public MyTime(String timeStr) {
            String[] tok = timeStr.split(":");
            this.hour = Integer.parseInt(tok[0]);
            this.min = Integer.parseInt(tok[1]);
            this.sec = Integer.parseInt(tok[2]);
        }

        public MyTime(String timeStr2, String timeStr1) {
            MyTime date1 = new MyTime(timeStr1);
            MyTime date2 = new MyTime(timeStr2);
            MyTime calced = date2.subtract(date1).selfCorrect();
            this.hour = calced.hour;
            this.min = calced.min;
            this.sec = calced.sec;
        }

        public MyTime subtract(MyTime time){
            return new MyTime(this.hour-time.hour, this.min-time.min, this.sec-time.sec);
        }

        public MyTime add(MyTime time){
            return new MyTime(this.hour+time.hour, this.min+time.min, this.sec+time.sec);
        }

        public MyTime selfCorrect(){
            while (sec < 0) {
                sec += 60;
                min -= 1;
            }
            while (sec >= 60){
                sec -= 60;
                min += 1;
            }
            while (min < 0) {
                min += 60;
                hour -= 1;
            }
            while (min >= 60){
                min -= 60;
                hour += 1;
            }
            return this;
        }

        @Override
        public String toString() {
            return String.valueOf(hour) + " " + String.valueOf(min) + " " + String.valueOf(sec);
        }

        @Override
        public int compareTo(MyTime o) {
            return Integer.compare(hour*3600 + min*60 + sec, o.hour*3600 + o.min*60 + o.sec) ;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int tc = Integer.parseInt(sc.nextLine());
        while(tc-->0){
            ArrayList<Record> records = new ArrayList<>();
            ArrayList<String> watchMan = new ArrayList<>();
            HashSet<String> empSet = new HashSet<>();
            while(true){
                String line = sc.nextLine();
                if(line.equals("#")) break;
                String[] toks = line.split("-");
                if(toks.length == 3) {
                    empSet.add(toks[1]);
                    records.add(new Record(toks[0], toks[1], toks[2]));
                }
                else watchMan.add(new String(line));
            }

            Collections.sort(records);
            Collections.sort(watchMan);
            TreeMap<String, MyTime> minEmpHour = new TreeMap<>();
            TreeMap<String, MyTime> maxEmpHour = new TreeMap<>();

            int rec = 0;
            for (int wm=0 ; wm<watchMan.size() ; wm++) {
                String[] curw = watchMan.get(wm).split(" ");
                String datew = curw[0];
                int beginRec = rec;
                TreeMap<String, MyTime> dateMinEmpHour = new TreeMap<>();
                TreeMap<String, MyTime> dateMaxEmpHour = new TreeMap<>();
                for (int wme = 1; wme < curw.length; wme++) {
                    String name = curw[wme];
                    if (!empSet.contains(name)) continue;
                    if(rec >= records.size()){
                        MyTime calcedTime1 = null;
                        String guessTime1;
                        if (rec > beginRec && records.get(rec - 1).date.equals(datew))
                            guessTime1 = records.get(rec - 1).time;
                        else guessTime1 = "08:00:00";
                        for (int i = beginRec; i < rec; i++) {
                            if (records.get(i).name.equals(name)) {
                                calcedTime1 = new MyTime(guessTime1, records.get(i).time);
                                break;
                            }
                        }
                        for (int i = rec + 1; i < records.size() && records.get(i).date.equals(datew); i++) {
                            if (records.get(i).name.equals(name)) {
                                calcedTime1 = new MyTime(records.get(i).time, guessTime1);
                                break;
                            }
                        }
                        MyTime calcedTime2 = null;
                        String guessTime2;
                        if (rec < records.size() && records.get(rec).date.equals(datew)) guessTime2 = records.get(rec).time;
                        else guessTime2 = "20:00:00";
                        for (int i = beginRec; i < rec; i++) {
                            if (records.get(i).name.equals(name)) {
                                calcedTime2 = new MyTime(guessTime2, records.get(i).time);
                                break;
                            }
                        }
                        for (int i = rec + 1; i < records.size() && records.get(i).date.equals(datew); i++) {
                            if (records.get(i).name.equals(name)) {
                                calcedTime2 = new MyTime(records.get(i).time, guessTime2);
                                break;
                            }
                        }
                        if (calcedTime1.compareTo(calcedTime2) < 0) {
                            dateMinEmpHour.put(name, calcedTime1);
                            dateMaxEmpHour.put(name, calcedTime2);
                        } else {
                            dateMinEmpHour.put(name, calcedTime2);
                            dateMaxEmpHour.put(name, calcedTime1);
                        }
                        continue;
                    }
                    Record record = records.get(rec);
                    if (!record.date.equals(datew)) break;

                    if (record.name.equals(name)) {
                        if (!dateMaxEmpHour.containsKey(name)) {
                            for (int i = rec + 1; i < records.size() && records.get(i).date.equals(datew); i++) {
                                if (records.get(i).name.equals(name)) {
                                    MyTime calcedTime = new MyTime(records.get(i).time, records.get(rec).time);
                                    dateMaxEmpHour.put(name, calcedTime);
                                    dateMinEmpHour.put(name, calcedTime);
                                    break;
                                }
                            }
                        }
                        rec++;
                        continue;
                    } else {
                        MyTime calcedTime1 = null;
                        String guessTime1;
                        if (rec > beginRec && records.get(rec - 1).date.equals(datew))
                            guessTime1 = records.get(rec - 1).time;
                        else if (rec > beginRec && records.get(rec - 1).name.equals(name)){
                            guessTime1 = new MyTime(records.get(rec - 1).time).add(new MyTime("00:00:01")).toString().replace(" ", ":");
                        }
                        else guessTime1 = "08:00:00";
                        for (int i = beginRec; i < rec; i++) {
                            if (records.get(i).name.equals(name)) {
                                calcedTime1 = new MyTime(guessTime1, records.get(i).time);
                                break;
                            }
                        }
                        for (int i = rec + 1; i < records.size() && records.get(i).date.equals(datew); i++) {
                            if (records.get(i).name.equals(name)) {
                                calcedTime1 = new MyTime(records.get(i).time, guessTime1);
                                break;
                            }
                        }
                        MyTime calcedTime2 = null;
                        String guessTime2;
                        if (rec < records.size() && records.get(rec).date.equals(datew)) guessTime2 = records.get(rec).time;
                        else guessTime2 = "20:00:00";
                        for (int i = beginRec; i < rec; i++) {
                            if (records.get(i).name.equals(name)) {
                                calcedTime2 = new MyTime(guessTime2, records.get(i).time);
                                break;
                            }
                        }
                        for (int i = rec + 1; i < records.size() && records.get(i).date.equals(datew); i++) {
                            if (records.get(i).name.equals(name)) {
                                calcedTime2 = new MyTime(records.get(i).time, guessTime2);
                                break;
                            }
                        }
                        if (calcedTime1.compareTo(calcedTime2) < 0) {
                            dateMinEmpHour.put(name, calcedTime1);
                            dateMaxEmpHour.put(name, calcedTime2);
                        } else {
                            dateMinEmpHour.put(name, calcedTime2);
                            dateMaxEmpHour.put(name, calcedTime1);
                        }
                    }
                }
                Iterator it = dateMaxEmpHour.entrySet().iterator();
                while (it.hasNext()) {
                    Map.Entry<String, MyTime> entry = (Map.Entry<String, MyTime>) it.next();
                    if (maxEmpHour.containsKey(entry.getKey())) {
                        maxEmpHour.put(entry.getKey(), maxEmpHour.get(entry.getKey()).add(entry.getValue()));
                    } else {
                        maxEmpHour.put(entry.getKey(), entry.getValue());
                    }
                }

                it = dateMinEmpHour.entrySet().iterator();
                while (it.hasNext()) {
                    Map.Entry<String, MyTime> entry = (Map.Entry<String, MyTime>) it.next();
                    if (minEmpHour.containsKey(entry.getKey())) {
                        minEmpHour.put(entry.getKey(), minEmpHour.get(entry.getKey()).add(entry.getValue()));
                    } else {
                        minEmpHour.put(entry.getKey(), entry.getValue());
                    }
                }
            }
            Iterator it = minEmpHour.entrySet().iterator();
            while (it.hasNext()) {
                Map.Entry<String, MyTime> entry = (Map.Entry<String, MyTime>) it.next();
                System.out.println(entry.getKey() + "-" + entry.getValue() + "-" + maxEmpHour.get(entry.getKey()));
            }
            System.out.println("#");
        }
    }
}
