
int PKCS7_simple_smimecap(stack_st_X509_ALGOR *sk,int nid,int arg)

{
  X509_ALGOR *data;
  ASN1_OBJECT *pAVar1;
  ASN1_TYPE *pAVar2;
  ASN1_INTEGER *a;
  int iVar3;
  
  data = X509_ALGOR_new();
  if (data == (X509_ALGOR *)0x0) {
    iVar3 = 0x66;
  }
  else {
    ASN1_OBJECT_free(data->algorithm);
    pAVar1 = OBJ_nid2obj(nid);
    data->algorithm = pAVar1;
    if (arg < 1) {
LAB_08181922:
      sk_push(&sk->stack,data);
      return 1;
    }
    pAVar2 = ASN1_TYPE_new();
    data->parameter = pAVar2;
    if (pAVar2 == (ASN1_TYPE *)0x0) {
      iVar3 = 0x6e;
    }
    else {
      a = ASN1_INTEGER_new();
      if (a != (ASN1_INTEGER *)0x0) {
        iVar3 = ASN1_INTEGER_set(a,arg);
        if (iVar3 == 0) {
          ERR_put_error(0x21,0x77,0x41,"pk7_attr.c",0x76);
          return 0;
        }
        pAVar2 = data->parameter;
        (pAVar2->value).integer = a;
        pAVar2->type = 2;
        goto LAB_08181922;
      }
      iVar3 = 0x72;
    }
  }
  ERR_put_error(0x21,0x77,0x41,"pk7_attr.c",iVar3);
  return 0;
}

