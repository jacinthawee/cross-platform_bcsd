
int TS_find_cert(_STACK *param_1,X509 *param_2)

{
  int iVar1;
  int **ppiVar2;
  int *piVar3;
  int iVar4;
  _STACK **pp_Var5;
  X509_CINF *pXVar6;
  
  if (param_2 != (X509 *)0x0 && param_1 != (_STACK *)0x0) {
    X509_check_purpose(param_2,-1,0);
    for (iVar4 = 0; iVar1 = sk_num(param_1), iVar4 < iVar1; iVar4 = iVar4 + 1) {
      ppiVar2 = (int **)sk_value(param_1,iVar4);
      if (((**ppiVar2 == 0x14) &&
          (iVar1 = memcmp((void *)(*ppiVar2)[2],&param_2->rfc3779_addr,0x14), iVar1 == 0)) &&
         ((pp_Var5 = (_STACK **)ppiVar2[1], pp_Var5 == (_STACK **)0x0 ||
          ((((pXVar6 = param_2->cert_info, pXVar6 != (X509_CINF *)0x0 &&
             (iVar1 = sk_num(*pp_Var5), iVar1 == 1)) &&
            (piVar3 = (int *)sk_value(*pp_Var5,0), *piVar3 == 4)) &&
           ((iVar1 = X509_NAME_cmp((X509_NAME *)piVar3[1],pXVar6->issuer), iVar1 == 0 &&
            (iVar1 = ASN1_INTEGER_cmp((ASN1_INTEGER *)pp_Var5[1],pXVar6->serialNumber), iVar1 == 0))
           )))))) {
        return iVar4;
      }
    }
  }
  return -1;
}

