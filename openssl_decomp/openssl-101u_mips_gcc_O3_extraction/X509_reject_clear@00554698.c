
void X509_reject_clear(X509 *x)

{
  int iVar1;
  undefined4 in_a2;
  undefined4 in_a3;
  
  if ((*(int *)(x->sha1_hash + 0xc) != 0) &&
     (iVar1 = *(int *)(*(int *)(x->sha1_hash + 0xc) + 4), iVar1 != 0)) {
    (*(code *)PTR_sk_pop_free_006a7058)(iVar1,PTR_ASN1_OBJECT_free_006a7004,in_a2,in_a3,&_gp);
    *(undefined4 *)(*(int *)(x->sha1_hash + 0xc) + 4) = 0;
  }
  return;
}

