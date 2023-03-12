
int index_index(int *param_1)

{
  int iVar1;
  char *format;
  int iVar2;
  
  iVar1 = TXT_DB_create_index((TXT_DB *)param_1[1],3,(qual *)0x0,index_serial_LHASH_HASH + 1,
                              index_serial_LHASH_COMP + 1);
  if (iVar1 == 0) {
    iVar2 = param_1[1];
    format = "error creating serial number index:(%ld,%ld,%ld)\n";
LAB_000346dc:
    BIO_printf(bio_err,format,*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x14),
               *(undefined4 *)(iVar2 + 0x18));
    return iVar1;
  }
  if (*param_1 != 0) {
    iVar1 = TXT_DB_create_index((TXT_DB *)param_1[1],5,index_name_qual + 1,index_name_LHASH_HASH + 1
                                ,index_name_LHASH_COMP + 1);
    if (iVar1 == 0) {
      iVar2 = param_1[1];
      format = "error creating name index:(%ld,%ld,%ld)\n";
      goto LAB_000346dc;
    }
  }
  return 1;
}

