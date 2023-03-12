
int serial_cb(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = next_serial(param_2);
  if (iVar1 == 0) {
    (*(code *)PTR_TS_RESP_CTX_set_status_info_006a7e48)
              (param_1,2,"Error during serial number generation.");
    (*(code *)PTR_TS_RESP_CTX_add_failure_info_006a7e4c)(param_1,0x11);
    return 0;
  }
  iVar2 = (*(code *)PTR_BIO_new_file_006a6eac)(param_2,"w");
  if (iVar2 != 0) {
    iVar3 = (*(code *)PTR_i2a_ASN1_INTEGER_006a75f0)(iVar2,iVar1);
    if (0 < iVar3) {
      iVar3 = (*(code *)PTR_BIO_puts_006a6f58)(iVar2,"\n");
      if (0 < iVar3) goto LAB_004758c0;
    }
  }
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)PTR_bio_err_006a6e3c,"could not save serial number to %s\n",param_2);
LAB_004758c0:
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar2);
  return iVar1;
}

