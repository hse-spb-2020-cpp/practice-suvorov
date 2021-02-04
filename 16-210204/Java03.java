public class Java03 {
    static class Employee {
    }

    static class Developer extends Employee {
    }

    static class Manager extends Employee {
    }

    static void foo(Employee[] e) {
        e[0] = new Manager();
    }

    public static void main(String[] args) {
        Developer[] d = new Developer[1];
        foo(d);
    }
}
