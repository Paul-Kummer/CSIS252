void stringToDay(std::string& dayStr)
{
	if (dayStr == "Sat" || 
		dayStr == "Saturday" || 
		dayStr == "sat" || 
		dayStr == "saturday" || 
		dayStr == "S")
	{
		dayStr = "Saturday";
	}

	else if (dayStr == "Sun" || 
			dayStr == "Sunday" || 
			dayStr == "sun" || 
			dayStr == "sunday" || 
			dayStr == "U")
	{
		dayStr = "Sunday";
	}

	else if (dayStr == "Mon" || 
			dayStr == "Monday" || 
			dayStr == "mon" || 
			dayStr == "monday" || 
			dayStr == "M")
	{
		dayStr = "Monday";
	}

	else if (dayStr == "Tue" || 
			dayStr == "Tues" || 
			dayStr == "Tuesday" || 
			dayStr == "tue" || 
			dayStr == "tues" || 
			dayStr == "tuesday" || 
			dayStr == "T" || 
			dayStr == "Tu")
	{
		dayStr = "Tuesday";
	}
	
	else if (dayStr == "Wed" || 
			dayStr == "Wednesday" || 
			dayStr == "wed" || 
			dayStr == "wednesday" || 
			dayStr == "W")
	{
		dayStr = "Wednesday";
	}

	else if (dayStr == "Thu" || 
			dayStr == "Thur" || 
			dayStr == "Thurs" || 
			dayStr == "Thursday" || 
			dayStr == "thu" || 
			dayStr == "thur" || 
			dayStr == "thurs" || 
			dayStr == "thursday" ||
			dayStr == "Th" ||
			dayStr == "R")
	{
		dayStr = "Thursday";
	}

	else if (dayStr == "Fri" || 
			dayStr == "Friday" || 
			dayStr == "fri" || 
			dayStr == "friday" || 
			dayStr == "F")
	{
		dayStr = "Friday";
	}

	else
	{
		dayStr = "Unknown";
	}
}