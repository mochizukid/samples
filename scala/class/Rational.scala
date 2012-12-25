class Rational(n: Int, d: Int) {
  require(d != 0)
  
  private val g = gcd(n.abs, d.abs)
  val numer = n / g;
  val denom = d / g;
  
  def + (that: Rational): Rational = 
    new Rational(numer * that.denom + denom * that.numer,
		 denom * that.denom)
  
  def * (that: Rational): Rational = 
    new Rational(numer * that.numer, denom * that.denom)
  
  override def toString() = numer + "/" + denom

  private def gcd(a: Int, b: Int): Int =
    if (b == 0) a else gcd(b, a % b)
}


val a = new Rational(1, 3)
println(a)

val b = new Rational(1, 2)
println(b)

val c = a + b
println(c)

val d = a * b
println(d)

val e = a + a * b
println(e)
