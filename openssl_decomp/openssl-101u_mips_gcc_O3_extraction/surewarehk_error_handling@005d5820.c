
void surewarehk_error_handling(char *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  switch(param_3) {
  case 1:
    *param_1 = '\0';
    return;
  case 0xfffffffb:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,param_2,0x6a,"e_sureware.c",0x27b);
    break;
  case 0xfffffffc:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,param_2,0x67,"e_sureware.c",0x278);
    break;
  case 0xfffffffd:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,param_2,0x68,"e_sureware.c",0x272);
    break;
  case 0xfffffffe:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,param_2,0x66,"e_sureware.c",0x275);
    break;
  default:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,param_2,0x65,"e_sureware.c",0x27e);
  }
  if ((*param_1 != '\0') && ((*(code *)PTR_ERR_add_error_data_006a813c)(1,param_1), logstream != 0))
  {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x15,"e_sureware.c",0x286);
    uVar1 = (*(code *)PTR_strlen_006a9a24)(param_1);
    (*(code *)PTR_BIO_write_006a6e14)(logstream,param_1,uVar1);
                    /* WARNING: Could not recover jumptable at 0x005d5940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x15,"e_sureware.c",0x288);
    return;
  }
  return;
}

