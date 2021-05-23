#include <gtest.h>
#include <TPlex.h>

TEST(TPlex, can_create_empty_plex) 
{
  ASSERT_NO_THROW(TPlex A);
}

TEST(TPlex, can_create_non_empty_plex) 
{
	TPoint a(12, 23);
	TPoint b(34, 45);
	
  ASSERT_NO_THROW(TPlex q(&a, &b));
}

TEST(TPlex, can_create_plex_from_char) 
{
	TPoint a(12, 23);
	TPoint b(34, 45);

	ASSERT_NO_THROW(TPlex q(&a, &b));
}

TEST(TPlex, can_add_line_in_plex) 
{
	TPoint a(12, 23);
	TPoint b(34, 45);
	TPoint c(56, 67);

	TPlex q(&a, &b);

  ASSERT_NO_THROW(q.AddLine(&b, &c));
}

TEST(TLine, can_create_line) 
{
	TPoint a(12, 23);
	TPoint b(34, 45);
  
  ASSERT_NO_THROW(TLine AB(a, b));
}

TEST(TSquare, can_create_square) 
{
	TPoint a(12, 23);
	TPoint b(34, 45);
	TPoint c(56, 67);
	TPoint d(89, 110);

	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	ASSERT_NO_THROW(TSquare ABCD(AB, BC, CD, DA));
}

TEST(TCanvas, can_get_empty_canvas)
{
	ASSERT_NO_THROW(TCanvas z);
}

TEST(TCanvas, can_get_canvas_from_plex) 
{
	TPoint a(12, 23);
	TPoint b(34, 45);
	TPlex q(&a, &b);

	TCanvas z;
	ASSERT_NO_THROW(z.AddObj(&q));
}

TEST(TCanvas, can_get_canvas_from_line)
{
	TPoint a(12, 23);
	TPoint b(34, 45);

	TLine AB(a, b);

	TCanvas z;
	ASSERT_NO_THROW(z.AddObj(&AB));
}

TEST(TCanvas, can_get_canvas_from_point)
{
	TPoint a(12, 23);

	TCanvas z;
	ASSERT_NO_THROW(z.AddObj(&a));
}

TEST(TCanvas, can_get_canvas_from_square)
{
	TPoint a(12, 23);
	TPoint b(34, 45);
	TPoint c(56, 67);
	TPoint d(89, 110);

	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TSquare ABCD(AB, BC, CD, DA);

	TCanvas z;
	ASSERT_NO_THROW(z.AddObj(&ABCD));
}

TEST(Print, can_use_print_to_point)
{
	TPoint a(12, 23);
	ASSERT_NO_THROW(a.Print());
}

TEST(Print, can_use_print_to_plex)
{
	TPoint a(12, 23);
	TPoint b(34, 45);

	TPlex q(&a, &b);
	ASSERT_NO_THROW(q.Print());
}

TEST(Print, can_use_print_to_line)
{
	TPoint a(12, 23);
	TPoint b(34, 45);

	TLine l(a, b);
	ASSERT_NO_THROW(l.Print());
}

TEST(Print, can_use_print_all)
{
	TPoint a(12, 23);
	TPoint b(34, 45);

	TPlex q(&a, &b);
	ASSERT_NO_THROW(q.PrintAll());
}
