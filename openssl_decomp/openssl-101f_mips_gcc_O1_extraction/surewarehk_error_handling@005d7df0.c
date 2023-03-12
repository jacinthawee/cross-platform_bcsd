
void surewarehk_error_handling(char *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  switch(param_3) {
  case 1:
    *param_1 = '\0';
    return;
  case 0xfffffffb:
    (*(code *)PTR_ERR_put_error_006a9030)(0x26,param_2,0x6a,"e_sureware.c",0x254);
    break;
  case 0xfffffffc:
    (*(code *)PTR_ERR_put_error_006a9030)(0x26,param_2,0x67,"e_sureware.c",0x251);
    break;
  case 0xfffffffd:
    (*(code *)PTR_ERR_put_error_006a9030)(0x26,param_2,0x68,"e_sureware.c",0x24b);
    break;
  case 0xfffffffe:
    (*(code *)PTR_ERR_put_error_006a9030)(0x26,param_2,0x66,"e_sureware.c",0x24e);
    break;
  default:
    (*(code *)PTR_ERR_put_error_006a9030)(0x26,param_2,0x65,"e_sureware.c",599);
  }
  if ((*param_1 != '\0') && ((*(code *)PTR_ERR_add_error_data_006a9264)(1,param_1), logstream != 0))
  {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x15,"e_sureware.c",0x261);
    uVar1 = (*(code *)PTR_strlen_006aab30)(param_1);
    (*(code *)PTR_BIO_write_006a7f14)(logstream,param_1,uVar1);
                    /* WARNING: Could not recover jumptable at 0x005d7f10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x15,"e_sureware.c",0x263);
    return;
  }
  return;
}

