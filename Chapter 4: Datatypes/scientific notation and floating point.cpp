/*
Scientific Notation
    Scientific notation serves as shorthand for lengthy numbers. They take the form of significant * 10 ^ (exponent)
        Exponents can be difficult to display, so 5.99 * 10^24 is instead written as 5.99e24.
        This exponent is negative for numbers whose magnitude is less than 1.
        
        The significand has one digit before (to the left of) the decimal point.
        The number of digits in the significand is known as the number of significant digits/figures. 
            More sig figs -> more precise
    Decimal numbers -> Scientific Notation
        Your exponent starts at zero.
        If the number has no explicit decimal point (e.g. 123), it is implicitly on the right end (e.g. 123.)
        Slide the decimal point left or right so there is only one non-zero digit to the left of the decimal.
        Each place you slide the decimal point to the left increases the exponent by 1.
        Each place you slide the decimal point to the right decreases the exponent by 1.
        Trim off any leading zeros (on the left end of the significand)
        Trim off any trailing zeros (on the right end of the significand) only if the original number had no decimal point. We’re assuming they’re not significant. If you have additional information to suggest they are significant, you can keep them
*/