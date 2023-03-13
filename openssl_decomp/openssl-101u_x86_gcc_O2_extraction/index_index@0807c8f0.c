
undefined4 index_index(int *param_1)

{
  int iVar1;
  
  iVar1 = TXT_DB_create_index((TXT_DB *)param_1[1],3,(qual *)0x0,index_serial_LHASH_HASH,
                              index_serial_LHASH_COMP);
  if (iVar1 == 0) {
    iVar1 = param_1[1];
    BIO_printf(bio_err,"error creating serial number index:(%ld,%ld,%ld)\n",
               *(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),
               *(undefined4 *)(iVar1 + 0x18));
    return 0;
  }
  if (*param_1 != 0) {
    iVar1 = TXT_DB_create_index((TXT_DB *)param_1[1],5,index_name_qual,index_name_LHASH_HASH,
                                index_name_LHASH_COMP);
    if (iVar1 == 0) {
      iVar1 = param_1[1];
      BIO_printf(bio_err,"error creating name index:(%ld,%ld,%ld)\n",*(undefined4 *)(iVar1 + 0x10),
                 *(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x18));
      return 0;
    }
  }
  return 1;
}

