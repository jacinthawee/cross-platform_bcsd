
int GENERAL_NAME_cmp(GENERAL_NAME *a,GENERAL_NAME *b)

{
  OTHERNAME *pOVar1;
  OTHERNAME *pOVar2;
  int iVar3;
  ASN1_TYPE *a_00;
  
  if (((a != (GENERAL_NAME *)0x0) && (b != (GENERAL_NAME *)0x0)) && (a->type == b->type)) {
    switch(a->type) {
    case 0:
      pOVar1 = (a->d).otherName;
      pOVar2 = (b->d).otherName;
      if (pOVar1 == (OTHERNAME *)0x0) {
        return -1;
      }
      if (pOVar2 == (OTHERNAME *)0x0) {
        return -1;
      }
      iVar3 = OBJ_cmp(pOVar1->type_id,pOVar2->type_id);
      if (iVar3 != 0) {
        return iVar3;
      }
      b = (GENERAL_NAME *)pOVar2->value;
      a_00 = pOVar1->value;
      break;
    case 1:
    case 2:
    case 6:
      iVar3 = ASN1_STRING_cmp((ASN1_STRING *)(a->d).otherName,(ASN1_STRING *)(b->d).otherName);
      return iVar3;
    case 3:
    case 5:
      b = (GENERAL_NAME *)(b->d).otherName;
      a_00 = (a->d).x400Address;
      break;
    case 4:
      iVar3 = X509_NAME_cmp((a->d).directoryName,(b->d).directoryName);
      return iVar3;
    case 7:
      iVar3 = ASN1_OCTET_STRING_cmp((ASN1_STRING *)(a->d).otherName,(ASN1_STRING *)(b->d).otherName)
      ;
      return iVar3;
    case 8:
      iVar3 = OBJ_cmp((a->d).registeredID,(b->d).registeredID);
      return iVar3;
    default:
      goto switchD_0816be80_caseD_9;
    }
    iVar3 = ASN1_TYPE_cmp(a_00,(ASN1_TYPE *)b);
    return iVar3;
  }
switchD_0816be80_caseD_9:
  return -1;
}

