
void __do_global_ctors_aux(void)

{
  code **ppcVar1;
  code *pcVar2;
  
  if (__CTOR_LIST__ != (code *)0xffffffff) {
    ppcVar1 = &__CTOR_LIST__;
    pcVar2 = __CTOR_LIST__;
    do {
      ppcVar1 = ppcVar1 + -1;
      (*pcVar2)();
      pcVar2 = *ppcVar1;
    } while (pcVar2 != (code *)0xffffffff);
  }
  return;
}

