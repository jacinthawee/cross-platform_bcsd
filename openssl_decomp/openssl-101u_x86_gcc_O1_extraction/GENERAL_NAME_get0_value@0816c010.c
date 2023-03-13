
void * GENERAL_NAME_get0_value(GENERAL_NAME *a,int *ptype)

{
  char *pcVar1;
  
  if (ptype != (int *)0x0) {
    *ptype = a->type;
  }
  if ((uint)a->type < 9) {
    pcVar1 = (a->d).ptr;
    switch(a->type) {
    case 0:
      return pcVar1;
    default:
      return pcVar1;
    case 3:
    case 5:
      return pcVar1;
    case 4:
      return pcVar1;
    case 7:
      return pcVar1;
    case 8:
      return pcVar1;
    }
  }
  return (void *)0x0;
}

