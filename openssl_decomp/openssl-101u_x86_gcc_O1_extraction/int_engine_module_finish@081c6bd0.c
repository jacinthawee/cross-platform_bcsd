
void int_engine_module_finish(void)

{
  ENGINE *e;
  
  while( true ) {
    e = (ENGINE *)sk_pop(initialized_engines);
    if (e == (ENGINE *)0x0) break;
    ENGINE_finish(e);
  }
  sk_free(initialized_engines);
  initialized_engines = (_STACK *)0x0;
  return;
}

