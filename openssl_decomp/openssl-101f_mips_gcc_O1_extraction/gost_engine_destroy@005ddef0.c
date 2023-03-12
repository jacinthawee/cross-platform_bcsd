
undefined4 gost_engine_destroy(void)

{
  (*(code *)PTR_gost_param_free_006aa6a4)();
  pmeth_GostR3410_94 = 0;
  ameth_Gost28147_MAC = 0;
  pmeth_GostR3410_2001 = 0;
  pmeth_Gost28147_MAC = 0;
  ameth_GostR3410_94 = 0;
  ameth_GostR3410_2001 = 0;
  return 1;
}

