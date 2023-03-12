
int i2a_ACCESS_DESCRIPTION(BIO *bp,ACCESS_DESCRIPTION *a)

{
  undefined4 in_a2;
  undefined4 in_a3;
  
  (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(bp,a->method,in_a2,in_a3,&_gp);
  return 2;
}

