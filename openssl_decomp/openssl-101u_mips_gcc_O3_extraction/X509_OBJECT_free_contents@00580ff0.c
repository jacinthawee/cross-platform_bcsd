
void X509_OBJECT_free_contents(X509_OBJECT *a)

{
  if (a->type == 1) {
                    /* WARNING: Could not recover jumptable at 0x00581024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_X509_free_006a6e90)((a->data).ptr);
    return;
  }
  if (a->type == 2) {
                    /* WARNING: Could not recover jumptable at 0x00581010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_X509_CRL_free_006a7060)((a->data).ptr);
    return;
  }
  return;
}

