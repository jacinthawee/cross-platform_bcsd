
undefined4 TS_MSG_IMPRINT_print_bio(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  char *pcVar3;
  
  puVar1 = (undefined4 *)TS_MSG_IMPRINT_get_algo(param_2);
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar1);
  if (iVar2 == 0) {
    pcVar3 = "UNKNOWN";
  }
  else {
    pcVar3 = (char *)(*(code *)PTR_OBJ_nid2ln_006a821c)(iVar2);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Hash Algorithm: %s\n",pcVar3);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Message data:\n");
  puVar1 = (undefined4 *)TS_MSG_IMPRINT_get_msg(param_2);
  (*(code *)PTR_BIO_dump_indent_006a8434)(param_1,puVar1[2],*puVar1,4);
  return 1;
}

