
void policy_data_free(byte *param_1)

{
  ASN1_OBJECT_free(*(ASN1_OBJECT **)(param_1 + 4));
  if ((*param_1 & 4) == 0) {
    sk_pop_free(*(_STACK **)(param_1 + 8),POLICYQUALINFO_free);
  }
  sk_pop_free(*(_STACK **)(param_1 + 0xc),ASN1_OBJECT_free);
  CRYPTO_free(param_1);
  return;
}

