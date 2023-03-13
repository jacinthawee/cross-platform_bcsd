
stack_st_X509_EXTENSION * X509_REQ_get_extensions(X509_REQ *req)

{
  char **ppcVar1;
  int iVar2;
  X509_ATTRIBUTE *pXVar3;
  stack_st_X509_EXTENSION *psVar4;
  stack_st_ASN1_TYPE *psVar5;
  X509_REQ_INFO *pXVar6;
  int *piVar7;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((((req != (X509_REQ *)0x0) && (pXVar6 = req->req_info, pXVar6 != (X509_REQ_INFO *)0x0)) &&
      (ext_nids != (undefined *)0x0)) &&
     (iVar2 = *(int *)ext_nids, piVar7 = (int *)ext_nids, iVar2 != 0)) {
    while( true ) {
      iVar2 = X509at_get_attr_by_NID(pXVar6->attributes,iVar2,-1);
      if (iVar2 != -1) break;
      piVar7 = piVar7 + 1;
      iVar2 = *piVar7;
      if (iVar2 == 0) goto LAB_0815c28a;
      pXVar6 = req->req_info;
    }
    pXVar3 = X509at_get_attr(req->req_info->attributes,iVar2);
    if (pXVar3->single == 0) {
      iVar2 = sk_num((_STACK *)(pXVar3->value).set);
      if (iVar2 == 0) goto LAB_0815c28a;
      psVar5 = (stack_st_ASN1_TYPE *)sk_value((_STACK *)(pXVar3->value).set,0);
    }
    else {
      psVar5 = (pXVar3->value).set;
    }
    if ((psVar5 != (stack_st_ASN1_TYPE *)0x0) && ((psVar5->stack).num == 0x10)) {
      ppcVar1 = (psVar5->stack).data;
      local_14 = (uchar *)ppcVar1[2];
      psVar4 = (stack_st_X509_EXTENSION *)
               ASN1_item_d2i((ASN1_VALUE **)0x0,&local_14,(long)*ppcVar1,
                             (ASN1_ITEM *)X509_EXTENSIONS_it);
      goto LAB_0815c25e;
    }
  }
LAB_0815c28a:
  psVar4 = (stack_st_X509_EXTENSION *)0x0;
LAB_0815c25e:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return psVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

