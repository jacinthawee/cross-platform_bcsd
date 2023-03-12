
void def_cleanup_cb(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (*(code *)PTR_sk_pop_free_006a7058)
            (*(undefined4 *)((int)param_1 + 4),def_cleanup_util_cb,param_3,param_4,&_gp);
  CRYPTO_free(param_1);
  return;
}

