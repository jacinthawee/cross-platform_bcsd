
void * sk_set(_STACK *param_1,int param_2,void *param_3)

{
  if (((param_1 != (_STACK *)0x0) && (-1 < param_2)) && (param_2 < param_1->num)) {
    param_1->data[param_2] = (char *)param_3;
    return param_3;
  }
  return (void *)0x0;
}

