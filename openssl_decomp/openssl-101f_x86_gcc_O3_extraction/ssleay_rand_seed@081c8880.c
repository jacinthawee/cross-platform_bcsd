
void ssleay_rand_seed(undefined4 param_1,int param_2)

{
  ssleay_rand_add(param_1,param_2,(double)param_2);
  return;
}

