#include "../../includes/minirt.h"

void	test1(void)
{
	t_ray		*r;
	t_ray		*r2;
	t_point		*p;
	t_vector	*v;
	t_tuple		*tp;
	double		**m;

	r = malloc(sizeof(t_ray));
	p = malloc(sizeof(t_point));
	v = malloc(sizeof(t_vector));
	tp = malloc(sizeof(t_tuple));
	p->x = 1;
	p->y = 2;
	p->z = 3;
	v->x = 0;
	v->y = 1;
	v->z = 0;
	tp->x = 3;
	tp->y = 4;
	tp->z = 5;
	tp->w = 1;
	r = create_ray(p, v);
	m = translation(tp);
	r2 = transform(r, m);
	printf("origin: %lf, %lf, %lf\n",
		r2->origin->x, r2->origin->y, r2->origin->z);
	printf("direction: %lf, %lf, %lf\n",
		r2->direction->x, r2->direction->y, r2->direction->z);
}

void	test2(void)
{
	t_ray		*r;
	t_ray		*r2;
	t_point		*p;
	t_vector	*v;
	t_tuple		*tp;
	double		**m;

	r = malloc(sizeof(t_ray));
	p = malloc(sizeof(t_point));
	v = malloc(sizeof(t_vector));
	tp = malloc(sizeof(t_tuple));
	p->x = 1;
	p->y = 2;
	p->z = 3;
	v->x = 0;
	v->y = 1;
	v->z = 0;
	tp->x = 2;
	tp->y = 3;
	tp->z = 4;
	tp->w = 1;
	r = create_ray(p, v);
	m = scaling(tp);
	r2 = transform(r, m);
	printf("origin: %lf, %lf, %lf\n",
		r2->origin->x, r2->origin->y, r2->origin->z);
	printf("direction: %lf, %lf, %lf\n",
		r2->direction->x, r2->direction->y, r2->direction->z);
}

void	test3(void)
{
	t_sphere	*s;
	double		**t;
	t_tuple		*tp;

	s = malloc(sizeof(t_sphere));
	tp = malloc(sizeof(t_tuple));
	tp->x = 2;
	tp->y = 3;
	tp->z = 4;
	tp->w = 1;
	t = translation(tp);
	s = sphere();
	printf("sphere id: %d; rad: %lf;\n",
		s->id, s->radius);
	print_matrix(s->transform, 4);
	set_transform(s, t);
	printf("______________________\n");
	print_matrix(s->transform, 4);
}

void	test4(void)
{
	t_ray		*r;
	t_sphere	*s;
	t_tuple		*tp;
	t_point		*p;
	t_vector	*v;
	t_intersect	*xs;

	r = malloc(sizeof(t_ray));
	s = malloc(sizeof(t_sphere));
	tp = malloc(sizeof(t_tuple));
	p = malloc(sizeof(t_point));
	v = malloc(sizeof(t_vector));
	p->x = 0;
	p->y = 0;
	p->z = -5;
	v->x = 0;
	v->y = 0;
	v->z = 1;
	tp->x = 2;
	tp->y = 2;
	tp->z = 2;
	tp->w = 1;
	s = sphere();
	r = create_ray(p, v);
	printf("sphere id: %d; rad: %lf;\n",
		s->id, s->radius);
	print_matrix(s->transform, 4);
	set_transform(s, scaling(tp));
	printf("______________________\n");
	print_matrix(s->transform, 4);

	xs = intersect(s, r);
	printf("xs count: %d, value 1: %lf, value 2: %lf\n", 
		xs->count, xs->value[0], xs->value[1]);
}

void	test5(void)
{
	t_ray		*r;
	t_sphere	*s;
	t_tuple		*tp;
	t_point		*p;
	t_vector	*v;
	t_intersect	*xs;

	r = malloc(sizeof(t_ray));
	s = malloc(sizeof(t_sphere));
	tp = malloc(sizeof(t_tuple));
	p = malloc(sizeof(t_point));
	v = malloc(sizeof(t_vector));
	p->x = 0;
	p->y = 0;
	p->z = -5;
	v->x = 0;
	v->y = 0;
	v->z = 1;
	tp->x = 2;
	tp->y = 2;
	tp->z = 2;
	tp->w = 1;
	s = sphere();
	r = create_ray(p, v);
	printf("sphere id: %d; rad: %lf;\n",
		s->id, s->radius);
	print_matrix(s->transform, 4);
	set_transform(s, translation(tp));
	printf("______________________\n");
	print_matrix(s->transform, 4);
	
	xs = intersect(s, r);
	printf("xs count: %d, value 1: %lf, value 2: %lf\n", 
		xs->count, xs->value[0], xs->value[1]);
}

int	main(void)
{
	test5();
	return (0);
}