
undefined4 cmac_signctx_init(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(param_2,0x100,param_3,param_4,&_gp);
  *(code **)(param_2 + 0x14) = int_update;
  return 1;
}

