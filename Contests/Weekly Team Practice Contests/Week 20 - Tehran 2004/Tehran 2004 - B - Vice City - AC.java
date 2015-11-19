import java.util.*;

public class Main {
    static final int INF = (int)1e9;

    static double[][] dist;
    public static HashMap<String, Integer> mpCars;
    public static HashMap<String, Integer> mpCities;
    public static ArrayList<Double> carSpeed;
    public static ArrayList<Integer> cityCar;
    public static ArrayList<ToNode>[] adj;

    public static class ToNode {
        public int v;
        public double w;
        public ToNode(int v, double w) {
            this.v = v;
            this.w = w;
        }
    }

    public static class QEntry {
        public int u;
        public int car;
        public double cost;
        public QEntry(int u, int car, double cost) {
            this.u = u;
            this.car = car;
            this.cost = cost;
        }
    }


    private static double dijkstra(int s, int t) {
        for(int i = 0 ; i <dist.length ; i++)  Arrays.fill(dist[i], INF);
        PriorityQueue<QEntry> q = new PriorityQueue<>(10, new Comparator<QEntry>() {
            @Override
            public int compare(QEntry o1, QEntry o2) {
                return Double.compare(o1.cost, o2.cost);
            }
        });

        q.add(new QEntry(s, cityCar.get(s), 0)); dist[s][cityCar.get(s)] = 0;

        while (!q.isEmpty()) {
            QEntry u = q.poll();
            if(u.u == t) return u.cost;
            if(u.cost > dist[u.u][u.car]) continue;
            for(int i=0 ; i<adj[u.u].size() ; i++) {
                // dont change car
                QEntry v = new QEntry(adj[u.u].get(i).v,
                        u.car, u.cost+(adj[u.u].get(i).w/carSpeed.get(u.car)));
                if(dist[v.u][v.car] > v.cost) {
                    dist[v.u][v.car] = v.cost;
                    q.add(v);
                }

                // change car
                v = new QEntry(adj[u.u].get(i).v,
                        cityCar.get(u.u), u.cost+(adj[u.u].get(i).w/carSpeed.get(cityCar.get(u.u)))+1/60.0);
                if(dist[v.u][v.car] > v.cost) {
                    dist[v.u][v.car] = v.cost;
                    q.add(v);
                }
            }
        }
        return INF; // inf
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = Integer.parseInt(sc.nextLine().trim());

        while (tc-->0) {
            mpCars = new HashMap<>();
            mpCities = new HashMap<>();
            carSpeed = new ArrayList<>();
            cityCar = new ArrayList<>();

            int nCars = 0;
            while (true) {
                String line = sc.nextLine().trim();
                if(line.equals("")) break;
                String[] tokens = line.split("\\s+");
                if(!mpCars.containsKey(tokens[0])) {
                    mpCars.put(tokens[0], nCars++);
                    int kms = Integer.parseInt(tokens[1]);
                    carSpeed.add((double)kms);
                }
            }

            int nCities = 0;
            while (true) {
                String line = sc.nextLine().trim();
                if(line.equals("")) break;
                String[] tokens = line.split("\\s+");
                if(!mpCities.containsKey(tokens[0])) {
                    mpCities.put(tokens[0], nCities++);
                    Integer car = mpCars.get(tokens[1]);
                    cityCar.add(car);
                }
            }
            adj = new ArrayList[nCities];
            for(int i=0 ; i<nCities; i++) adj[i] = new ArrayList<>();
            while (true) {
                String line = sc.nextLine().trim();
                if(line.trim().equals("*")) break;
                if(line.trim().equals("")) continue;
                String[] tokens = line.split("\\s+");
                int u = mpCities.get(tokens[0]);
                int v = mpCities.get(tokens[1]);
                double w = Double.parseDouble(tokens[2]);
                adj[u].add(new ToNode(v, w));
                adj[v].add(new ToNode(u, w));
            }

            int s = mpCities.get("PayPhone");
            int t = mpCities.get("WKCharriot");
            dist = new double[nCities][nCars];
            double ans = dijkstra(s, t);

            if(ans>=INF) System.out.println("UNREACHABLE");
            else System.out.printf("%.3f\n", ans*60.-0.0005 + 1e-9);
        }
    }
}