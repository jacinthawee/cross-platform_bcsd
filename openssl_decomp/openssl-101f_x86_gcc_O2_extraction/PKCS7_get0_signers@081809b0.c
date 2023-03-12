
stack_st_X509 * PKCS7_get0_signers(PKCS7 *p7,stack_st_X509 *certs,int flags)

{
  X509_NAME **ppXVar1;
  stack_st_X509 *psVar2;
  int iVar3;
  _STACK *p_Var4;
  _STACK *st;
  int iVar5;
  void *pvVar6;
  X509 *pXVar7;
  
  if (p7 == (PKCS7 *)0x0) {
    iVar5 = 0x1b8;
    iVar3 = 0x8f;
  }
  else {
    iVar3 = OBJ_obj2nid(p7->type);
    if (iVar3 == 0x16) {
      p_Var4 = (_STACK *)PKCS7_get_signer_info(p7);
      iVar3 = sk_num(p_Var4);
      if (iVar3 < 1) {
        iVar5 = 0x1c6;
        iVar3 = 0x8e;
      }
      else {
        st = sk_new_null();
        if (st != (_STACK *)0x0) {
          if (certs == (stack_st_X509 *)0x0) {
            if ((flags & 0x10U) == 0) {
              for (iVar3 = 0; iVar5 = sk_num(p_Var4), iVar3 < iVar5; iVar3 = iVar3 + 1) {
                pvVar6 = sk_value(p_Var4,iVar3);
                psVar2 = ((p7->d).sign)->cert;
                if ((psVar2 == (stack_st_X509 *)0x0) ||
                   (pXVar7 = X509_find_by_issuer_and_serial
                                       (psVar2,**(X509_NAME ***)((int)pvVar6 + 4),
                                        (ASN1_INTEGER *)(*(X509_NAME ***)((int)pvVar6 + 4))[1]),
                   pXVar7 == (X509 *)0x0)) goto LAB_08180b0c;
                iVar5 = sk_push(st,pXVar7);
                if (iVar5 == 0) goto LAB_08180b40;
              }
            }
            else {
              iVar3 = sk_num(p_Var4);
              if (0 < iVar3) {
                sk_value(p_Var4,0);
LAB_08180b0c:
                ERR_put_error(0x21,0x7c,0x80,"pk7_smime.c",0x1dc);
                sk_free(st);
                return (stack_st_X509 *)0x0;
              }
            }
          }
          else {
            iVar3 = 0;
            if ((flags & 0x10U) == 0) {
              for (; iVar5 = sk_num(p_Var4), iVar3 < iVar5; iVar3 = iVar3 + 1) {
                pvVar6 = sk_value(p_Var4,iVar3);
                ppXVar1 = *(X509_NAME ***)((int)pvVar6 + 4);
                pXVar7 = X509_find_by_issuer_and_serial(certs,*ppXVar1,(ASN1_INTEGER *)ppXVar1[1]);
                if ((pXVar7 == (X509 *)0x0) &&
                   ((psVar2 = ((p7->d).sign)->cert, psVar2 == (stack_st_X509 *)0x0 ||
                    (pXVar7 = X509_find_by_issuer_and_serial
                                        (psVar2,*ppXVar1,(ASN1_INTEGER *)ppXVar1[1]),
                    pXVar7 == (X509 *)0x0)))) goto LAB_08180b0c;
                iVar5 = sk_push(st,pXVar7);
                if (iVar5 == 0) goto LAB_08180b40;
              }
            }
            else {
              iVar5 = sk_num(p_Var4);
              if (0 < iVar5) {
                do {
                  pvVar6 = sk_value(p_Var4,iVar3);
                  pXVar7 = X509_find_by_issuer_and_serial
                                     (certs,**(X509_NAME ***)((int)pvVar6 + 4),
                                      (ASN1_INTEGER *)(*(X509_NAME ***)((int)pvVar6 + 4))[1]);
                  if (pXVar7 == (X509 *)0x0) goto LAB_08180b0c;
                  iVar5 = sk_push(st,pXVar7);
                  if (iVar5 == 0) {
LAB_08180b40:
                    sk_free(st);
                    return (stack_st_X509 *)0x0;
                  }
                  iVar3 = iVar3 + 1;
                  iVar5 = sk_num(p_Var4);
                } while (iVar3 < iVar5);
              }
            }
          }
          return (stack_st_X509 *)st;
        }
        iVar5 = 0x1cb;
        iVar3 = 0x41;
      }
    }
    else {
      iVar5 = 0x1bd;
      iVar3 = 0x71;
    }
  }
  ERR_put_error(0x21,0x7c,iVar3,"pk7_smime.c",iVar5);
  return (stack_st_X509 *)0x0;
}

