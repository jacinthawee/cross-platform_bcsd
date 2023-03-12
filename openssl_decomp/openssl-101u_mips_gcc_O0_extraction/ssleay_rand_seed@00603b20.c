
void ssleay_rand_seed(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    return;
  }
  ssleay_rand_add_part_0
            (param_1,param_2,(int)((ulonglong)(double)param_2 >> 0x20),SUB84((double)param_2,0));
  return;
}

