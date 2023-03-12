
int X509_REQ_add_extensions_nid(X509_REQ *req,stack_st_X509_EXTENSION *exts,int nid)

{
  undefined *puVar1;
  ASN1_TYPE *a;
  ASN1_STRING *pAVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  stack_st_X509_ATTRIBUTE *psVar6;
  X509_REQ_INFO *pXVar7;
  
  a = ASN1_TYPE_new();
  if (a != (ASN1_TYPE *)0x0) {
    pAVar2 = ASN1_STRING_new();
    (a->value).asn1_string = pAVar2;
    puVar1 = PTR_X509_EXTENSIONS_it_006a9fdc;
    if (pAVar2 != (ASN1_STRING *)0x0) {
      a->type = 0x10;
      iVar3 = ASN1_item_i2d((ASN1_VALUE *)exts,&pAVar2->data,(ASN1_ITEM *)puVar1);
      puVar1 = PTR_X509_ATTRIBUTE_new_006a9fe0;
      pAVar2->length = iVar3;
      puVar4 = (undefined4 *)(*(code *)puVar1)();
      if (puVar4 == (undefined4 *)0x0) goto LAB_0057a66c;
      iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
      puVar4[2] = iVar3;
      if ((iVar3 == 0) ||
         (iVar3 = (*(code *)PTR_sk_push_006a80a8)(iVar3,a), puVar1 = PTR_OBJ_nid2obj_006a8240,
         iVar3 == 0)) goto LAB_0057a66c;
      puVar4[1] = 0;
      uVar5 = (*(code *)puVar1)(nid);
      pXVar7 = req->req_info;
      *puVar4 = uVar5;
      psVar6 = pXVar7->attributes;
      if (psVar6 == (stack_st_X509_ATTRIBUTE *)0x0) {
        psVar6 = (stack_st_X509_ATTRIBUTE *)(*(code *)PTR_sk_new_null_006a80a4)();
        pXVar7->attributes = psVar6;
        if (psVar6 != (stack_st_X509_ATTRIBUTE *)0x0) {
          psVar6 = req->req_info->attributes;
          goto LAB_0057a6dc;
        }
      }
      else {
LAB_0057a6dc:
        iVar3 = (*(code *)PTR_sk_push_006a80a8)(psVar6,puVar4);
        if (iVar3 != 0) {
          return 1;
        }
      }
      a = (ASN1_TYPE *)0x0;
      goto LAB_0057a66c;
    }
  }
  puVar4 = (undefined4 *)0x0;
LAB_0057a66c:
  (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(puVar4);
  ASN1_TYPE_free(a);
  return 0;
}

