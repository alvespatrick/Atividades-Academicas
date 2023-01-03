import pandas as pd
import numpy as np

df = pd.read_excel('Dados.xlsx')

total_correntes = df.shape[0]

tfinal, tinicial = np.array(df['Td']), np.array(df['To'])
dif_temperatura = tfinal - tinicial
data = np.array(['Fria' if info > 0 else 'Quente' for info in dif_temperatura])
df['Tipo de Corrente'] = data

data = np.array([f'{ini} - {fim}' for ini, fim in zip(tinicial, tfinal)])
df['Intervalo de Temperatura (ºC)'] = data

data = np.array([dif*coef if dif>0 else -dif*coef for dif, coef in zip(dif_temperatura, df['WCp'])])
df['Oferta/Demanda'] = data

oferta = df.loc[df['Tipo de Corrente'] == "Quente"]['Oferta/Demanda'].sum()
demanda = df.loc[df['Tipo de Corrente'] == "Fria"]['Oferta/Demanda'].sum()

min_vapor = demanda - oferta if demanda - oferta > 0 else 0
min_agua = oferta - demanda if oferta - demanda > 0 else 0

print(f'Intervalos de temperatura: {total_correntes}\nOferta total: {oferta}kW\nDemanda total: {demanda}kW\nConsumo mínimo de vapor: {min_vapor}kW\nConsumo mínimo de água: {min_agua}kW\n')
