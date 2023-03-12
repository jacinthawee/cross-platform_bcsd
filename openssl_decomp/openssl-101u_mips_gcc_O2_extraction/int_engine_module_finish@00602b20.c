
void int_engine_module_finish(void)

{
  int iVar1;
  
  while( true ) {
    iVar1 = (*(code *)PTR_sk_pop_006a8da4)(initialized_engines);
    if (iVar1 == 0) break;
    (*(code *)PTR_ENGINE_finish_006a6fc4)(iVar1);
  }
  (*(code *)PTR_sk_free_006a6e80)(initialized_engines);
  initialized_engines = 0;
  return;
}

