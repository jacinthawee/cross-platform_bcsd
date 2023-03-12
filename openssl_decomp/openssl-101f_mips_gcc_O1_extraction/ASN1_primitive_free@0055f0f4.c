
void ASN1_primitive_free(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  ASN1_OBJECT *a;
  ASN1_OBJECT *a_00;
  ASN1_OBJECT *a_01;
  code *UNRECOVERED_JUMPTABLE;
  
  if (it == (ASN1_ITEM *)0x0) {
    piVar2 = (int *)*pval;
    pval = (ASN1_VALUE **)(piVar2 + 1);
    a_00 = (ASN1_OBJECT *)piVar2[1];
    iVar3 = *piVar2;
    if (a_00 == (ASN1_OBJECT *)0x0) {
      return;
    }
    if (iVar3 == 1) {
      piVar2[1] = -1;
      return;
    }
    if (iVar3 < 2) goto joined_r0x0055f2e4;
    if (iVar3 == 5) goto LAB_0055f1e0;
    if (iVar3 == 6) goto LAB_0055f258;
  }
  else {
    if ((it->funcs != (void *)0x0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)((int)it->funcs + 0xc),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0055f140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    if (it->itype == '\x05') {
      a_00 = (ASN1_OBJECT *)*pval;
      if (a_00 == (ASN1_OBJECT *)0x0) {
        return;
      }
    }
    else {
      iVar3 = it->utype;
      if (iVar3 == 1) {
        *pval = (ASN1_VALUE *)it->size;
        return;
      }
      a_00 = (ASN1_OBJECT *)*pval;
      if (a_00 == (ASN1_OBJECT *)0x0) {
        return;
      }
      if (iVar3 == 5) goto LAB_0055f1e0;
      if (iVar3 == 6) {
LAB_0055f258:
        ASN1_OBJECT_free(a_00);
        *pval = (ASN1_VALUE *)0x0;
        return;
      }
joined_r0x0055f2e4:
      if (iVar3 == -4) {
        a_01 = (ASN1_OBJECT *)a_00->ln;
        pcVar1 = a_00->sn;
        if (a_01 != (ASN1_OBJECT *)0x0) {
          if (pcVar1 == (char *)0x1) {
            a_00->ln = (char **)0xffffffff;
          }
          else if ((int)pcVar1 < 2) {
            if (pcVar1 == (char *)0xfffffffc) {
              a = (ASN1_OBJECT *)a_01->ln;
              pcVar1 = a_01->sn;
              if (a != (ASN1_OBJECT *)0x0) {
                if (pcVar1 == (char *)0x1) {
                  a_01->ln = (char **)0xffffffff;
                }
                else {
                  if ((int)pcVar1 < 2) {
                    if (pcVar1 == (char *)0xfffffffc) {
                      ASN1_primitive_free_part_0(&a_01->ln,0);
                      (*(code *)PTR_CRYPTO_free_006a7f88)(a_01->ln);
                    }
                    else {
LAB_0055f350:
                      ASN1_STRING_free((ASN1_STRING *)a);
                    }
                  }
                  else if (pcVar1 != (char *)0x5) {
                    if (pcVar1 != (char *)0x6) goto LAB_0055f350;
                    ASN1_OBJECT_free(a);
                  }
                  a_01->ln = (char **)0x0;
                  a_01 = (ASN1_OBJECT *)a_00->ln;
                }
              }
              (*(code *)PTR_CRYPTO_free_006a7f88)(a_01);
              a_00->ln = (char **)0x0;
              a_00 = (ASN1_OBJECT *)*pval;
            }
            else {
LAB_0055f2f8:
              ASN1_STRING_free((ASN1_STRING *)a_01);
              a_00->ln = (char **)0x0;
              a_00 = (ASN1_OBJECT *)*pval;
            }
          }
          else {
            if (pcVar1 != (char *)0x5) {
              if (pcVar1 != (char *)0x6) goto LAB_0055f2f8;
              ASN1_OBJECT_free(a_01);
            }
            a_00->ln = (char **)0x0;
            a_00 = (ASN1_OBJECT *)*pval;
          }
        }
        (*(code *)PTR_CRYPTO_free_006a7f88)(a_00);
        goto LAB_0055f1e0;
      }
    }
  }
  ASN1_STRING_free((ASN1_STRING *)a_00);
  *pval = (ASN1_VALUE *)0x0;
LAB_0055f1e0:
  *pval = (ASN1_VALUE *)0x0;
  return;
}

