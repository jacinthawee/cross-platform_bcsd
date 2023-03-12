
int __regparm3 TS_find_cert(_STACK *param_1,X509 *param_2)

{
  _STACK **pp_Var1;
  X509_CINF *pXVar2;
  int iVar3;
  int **ppiVar4;
  int *piVar5;
  int iVar6;
  
  if ((param_1 == (_STACK *)0x0) || (param_2 == (X509 *)0x0)) {
    return -1;
  }
  iVar6 = 0;
  X509_check_purpose(param_2,-1,0);
  do {
    iVar3 = sk_num(param_1);
    if (iVar3 <= iVar6) {
      return -1;
    }
    ppiVar4 = (int **)sk_value(param_1,iVar6);
    if ((**ppiVar4 == 0x14) &&
       (iVar3 = memcmp((void *)(*ppiVar4)[2],&param_2->rfc3779_addr,0x14), iVar3 == 0)) {
      pp_Var1 = (_STACK **)ppiVar4[1];
      if (pp_Var1 == (_STACK **)0x0) {
        return iVar6;
      }
      pXVar2 = param_2->cert_info;
      if ((((pXVar2 != (X509_CINF *)0x0) && (iVar3 = sk_num(*pp_Var1), iVar3 == 1)) &&
          (piVar5 = (int *)sk_value(*pp_Var1,0), *piVar5 == 4)) &&
         ((iVar3 = X509_NAME_cmp((X509_NAME *)piVar5[1],pXVar2->issuer), iVar3 == 0 &&
          (iVar3 = ASN1_INTEGER_cmp((ASN1_INTEGER *)pp_Var1[1],pXVar2->serialNumber), iVar3 == 0))))
      {
        return iVar6;
      }
    }
    iVar6 = iVar6 + 1;
  } while( true );
}

