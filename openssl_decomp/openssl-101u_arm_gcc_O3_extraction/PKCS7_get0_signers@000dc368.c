
stack_st_X509 * PKCS7_get0_signers(PKCS7 *p7,stack_st_X509 *certs,int flags)

{
  int iVar1;
  _STACK *p_Var2;
  PKCS7 *st;
  void *pvVar3;
  X509 *pXVar4;
  int iVar5;
  stack_st_X509 *psVar6;
  uint uVar7;
  X509_NAME **ppXVar8;
  
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x7c,0x8f,"pk7_smime.c",0x1a8);
  }
  else {
    iVar1 = OBJ_obj2nid(p7->type);
    if (iVar1 != 0x16) {
      ERR_put_error(0x21,0x7c,0x71,"pk7_smime.c",0x1ad);
      return (stack_st_X509 *)0x0;
    }
    p_Var2 = (_STACK *)PKCS7_get_signer_info(p7);
    iVar1 = sk_num(p_Var2);
    if (iVar1 < 1) {
      ERR_put_error(0x21,0x7c,0x8e,"pk7_smime.c",0x1b6);
      p7 = (PKCS7 *)0x0;
    }
    else {
      st = (PKCS7 *)sk_new_null();
      if (st != (PKCS7 *)0x0) {
        uVar7 = flags & 0x10;
        if (certs == (stack_st_X509 *)0x0) {
          if (uVar7 != 0) {
            iVar1 = sk_num(p_Var2);
            if (iVar1 < 1) {
              return (stack_st_X509 *)st;
            }
            sk_value(p_Var2,0);
LAB_000dc434:
            ERR_put_error(0x21,0x7c,0x80,"pk7_smime.c",0x1ce);
            sk_free((_STACK *)st);
            return (stack_st_X509 *)0x0;
          }
          do {
            iVar1 = sk_num(p_Var2);
            if (iVar1 <= (int)uVar7) {
              return (stack_st_X509 *)st;
            }
            pvVar3 = sk_value(p_Var2,uVar7);
            psVar6 = ((p7->d).sign)->cert;
            if ((psVar6 == (stack_st_X509 *)0x0) ||
               (pXVar4 = X509_find_by_issuer_and_serial
                                   (psVar6,**(X509_NAME ***)((int)pvVar3 + 4),
                                    (ASN1_INTEGER *)(*(X509_NAME ***)((int)pvVar3 + 4))[1]),
               pXVar4 == (X509 *)0x0)) goto LAB_000dc434;
            iVar1 = sk_push((_STACK *)st,pXVar4);
            uVar7 = uVar7 + 1;
          } while (iVar1 != 0);
        }
        else if (uVar7 == 0) {
          do {
            iVar1 = sk_num(p_Var2);
            if (iVar1 <= (int)uVar7) {
              return (stack_st_X509 *)st;
            }
            pvVar3 = sk_value(p_Var2,uVar7);
            ppXVar8 = *(X509_NAME ***)((int)pvVar3 + 4);
            pXVar4 = X509_find_by_issuer_and_serial(certs,*ppXVar8,(ASN1_INTEGER *)ppXVar8[1]);
            if ((pXVar4 == (X509 *)0x0) &&
               ((psVar6 = ((p7->d).sign)->cert, psVar6 == (stack_st_X509 *)0x0 ||
                (pXVar4 = X509_find_by_issuer_and_serial(psVar6,*ppXVar8,(ASN1_INTEGER *)ppXVar8[1])
                , pXVar4 == (X509 *)0x0)))) goto LAB_000dc434;
            iVar1 = sk_push((_STACK *)st,pXVar4);
            uVar7 = uVar7 + 1;
          } while (iVar1 != 0);
        }
        else {
          iVar1 = 0;
          do {
            iVar5 = sk_num(p_Var2);
            if (iVar5 <= iVar1) {
              return (stack_st_X509 *)st;
            }
            pvVar3 = sk_value(p_Var2,iVar1);
            pXVar4 = X509_find_by_issuer_and_serial
                               (certs,**(X509_NAME ***)((int)pvVar3 + 4),
                                (ASN1_INTEGER *)(*(X509_NAME ***)((int)pvVar3 + 4))[1]);
            if (pXVar4 == (X509 *)0x0) goto LAB_000dc434;
            iVar5 = sk_push((_STACK *)st,pXVar4);
            iVar1 = iVar1 + 1;
          } while (iVar5 != 0);
        }
        sk_free((_STACK *)st);
        return (stack_st_X509 *)0x0;
      }
      ERR_put_error(0x21,0x7c,0x41,"pk7_smime.c",0x1bb);
      p7 = st;
    }
  }
  return (stack_st_X509 *)p7;
}

