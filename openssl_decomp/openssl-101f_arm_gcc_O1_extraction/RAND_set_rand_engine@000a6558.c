
int RAND_set_rand_engine(ENGINE *engine)

{
  int iVar1;
  RAND_METHOD *pRVar2;
  
  pRVar2 = (RAND_METHOD *)engine;
  if (engine != (ENGINE *)0x0) {
    iVar1 = ENGINE_init(engine);
    if (iVar1 == 0) {
      return 0;
    }
    pRVar2 = ENGINE_get_RAND(engine);
    if (pRVar2 == (RAND_METHOD *)0x0) {
      ENGINE_finish(engine);
      return 0;
    }
  }
  if (funct_ref != (ENGINE *)0x0) {
    ENGINE_finish(funct_ref);
  }
  funct_ref = engine;
  default_RAND_meth = pRVar2;
  return 1;
}

