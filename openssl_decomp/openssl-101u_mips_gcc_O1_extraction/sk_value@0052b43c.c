
void * sk_value(_STACK *param_1,int param_2)

{
  if (((param_1 != (_STACK *)0x0) && (-1 < param_2)) && (param_2 < param_1->num)) {
    return param_1->data[param_2];
  }
  return (void *)0x0;
}

