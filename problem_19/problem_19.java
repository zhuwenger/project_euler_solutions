import java.util.Calendar;

public class problem_19 {

	public static int countSundays() {
		Calendar c = Calendar.getInstance();
		c.set(Calendar.HOUR_OF_DAY, 0);
		c.set(Calendar.MINUTE, 0);
		c.set(Calendar.SECOND, 0);
		c.set(Calendar.MILLISECOND, 0);
		c.set(Calendar.MONTH, Calendar.JANUARY);
		c.set(Calendar.DATE, 1);
		c.set(Calendar.YEAR, 1901);

		int sum = 0;
		while (c.get(Calendar.YEAR) != 2001) {
			if (c.get(Calendar.DAY_OF_WEEK) == Calendar.SUNDAY
					&& c.get(Calendar.DATE) == 1) {
				sum++;
			}

			c.add(Calendar.DAY_OF_YEAR, 1);
		}

		return sum;
	}

	public static void main(final String[] args) {
		System.out.println(countSundays());
	}
}
