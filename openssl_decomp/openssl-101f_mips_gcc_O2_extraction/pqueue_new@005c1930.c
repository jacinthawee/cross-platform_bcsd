
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pqueue pqueue_new(void)

{
  pqueue p_Var1;
  undefined4 in_a3;
  
  p_Var1 = (pqueue)(*(code *)PTR_CRYPTO_malloc_006a8108)(8,"pqueue.c",0x5f,in_a3,&_gp);
  if (p_Var1 != (pqueue)0x0) {
    *p_Var1 = (_pqueue)0x0;
    p_Var1[1] = (_pqueue)0x0;
    p_Var1[2] = (_pqueue)0x0;
    p_Var1[3] = (_pqueue)0x0;
    p_Var1[4] = (_pqueue)0x0;
    p_Var1[5] = (_pqueue)0x0;
    p_Var1[6] = (_pqueue)0x0;
    p_Var1[7] = (_pqueue)0x0;
  }
  return p_Var1;
}

