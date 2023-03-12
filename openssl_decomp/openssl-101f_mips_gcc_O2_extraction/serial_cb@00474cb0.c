
int serial_cb(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = next_serial(param_2);
  if (iVar1 == 0) {
    (*(code *)PTR_TS_RESP_CTX_set_status_info_006a8f38)
              (param_1,2,"Error during serial number generation.");
    (*(code *)PTR_TS_RESP_CTX_add_failure_info_006a8f3c)(param_1,0x11);
    return 0;
  }
  iVar2 = (*(code *)PTR_BIO_new_file_006a7fac)(param_2,"w");
  if (iVar2 != 0) {
    iVar3 = (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(iVar2,iVar1);
    if (0 < iVar3) {
      iVar3 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"\n");
      if (0 < iVar3) goto LAB_00474d60;
    }
  }
  (*(code *)PTR_BIO_printf_006a7f38)
            (*(undefined4 *)PTR_bio_err_006a7f3c,"could not save serial number to %s\n",param_2);
LAB_00474d60:
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar2);
  return iVar1;
}

