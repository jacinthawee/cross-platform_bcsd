
undefined4 TS_MSG_IMPRINT_print_bio(BIO *param_1,undefined4 param_2)

{
  ASN1_OBJECT **ppAVar1;
  int n;
  int *piVar2;
  char *pcVar3;
  
  ppAVar1 = (ASN1_OBJECT **)TS_MSG_IMPRINT_get_algo(param_2);
  n = OBJ_obj2nid(*ppAVar1);
  pcVar3 = "UNKNOWN";
  if (n != 0) {
    pcVar3 = OBJ_nid2ln(n);
  }
  BIO_printf(param_1,"Hash Algorithm: %s\n",pcVar3);
  BIO_printf(param_1,"Message data:\n");
  piVar2 = (int *)TS_MSG_IMPRINT_get_msg(param_2);
  BIO_dump_indent(param_1,(char *)piVar2[2],*piVar2,4);
  return 1;
}

