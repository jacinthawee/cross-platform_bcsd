
int index_index(int *param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = (*(code *)PTR_TXT_DB_create_index_006a7bf8)
                    (param_1[1],3,0,index_serial_LHASH_HASH,index_serial_LHASH_COMP);
  if (iVar1 == 0) {
    iVar2 = param_1[1];
    pcVar3 = "error creating serial number index:(%ld,%ld,%ld)\n";
LAB_0045cfa4:
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,pcVar3,*(undefined4 *)(iVar2 + 0x10),
               *(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x18));
    return iVar1;
  }
  if (*param_1 != 0) {
    iVar1 = (*(code *)PTR_TXT_DB_create_index_006a7bf8)
                      (param_1[1],5,index_name_qual,index_name_LHASH_HASH,index_name_LHASH_COMP);
    if (iVar1 == 0) {
      iVar2 = param_1[1];
      pcVar3 = "error creating name index:(%ld,%ld,%ld)\n";
      goto LAB_0045cfa4;
    }
  }
  return 1;
}

