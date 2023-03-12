
int __regparm1 RAND_set_rand_engine(ENGINE *engine)

{
  int iVar1;
  RAND_METHOD *pRVar2;
  ENGINE *in_stack_00000004;
  
  if (in_stack_00000004 != (ENGINE *)0x0) {
    iVar1 = ENGINE_init(engine);
    if (iVar1 != 0) {
      pRVar2 = ENGINE_get_RAND(in_stack_00000004);
      if (pRVar2 != (RAND_METHOD *)0x0) goto LAB_081233ea;
      ENGINE_finish((ENGINE *)0x0);
      iVar1 = 0;
    }
    return iVar1;
  }
  pRVar2 = (RAND_METHOD *)0x0;
LAB_081233ea:
  if (funct_ref != (ENGINE *)0x0) {
    ENGINE_finish(funct_ref);
  }
  default_RAND_meth = pRVar2;
  funct_ref = in_stack_00000004;
  return 1;
}

