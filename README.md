![Desktop CI](https://github.com/akpaevj/BluetoothClient/workflows/Desktop%20CI/badge.svg)

# BluetoothClient
Компонента предоставляет методы для синхронного обмена данными с устройствами Bluetooth (RFCOMM)
### Свойства внешней компоненты:
Версия (Version) - строка, содержит текущую версию используемой компоненты.

Таймаут (Timeout) - число (целое), количество секунд таймаута операций чтения и записи. По умолчанию установлено значение 0, что соответствует ожиданию операции, пока активно соединение. Установку значения необходимо выполнять ДО вызова метода “Открыть”
### Методы внешней компоненты:
-----------
#### Название метода:
Открыть (Open)
#### Параметры метода:
Название устройства (строка) - название bluetooth устройства, показывает при обнаружении.
#### Возвращаемое значение:
Нет
#### Описание метода:
Выполняет поиск устройства по переданному имени и открывает к нему подключение. Может вызывать исключение.
#### Пример:
```
Соединение.Открыть("Device name");
```
-----------
#### Название метода:
Открыто (Opened)
#### Параметры метода:
Нет
#### Возвращаемое значение:
Истина - если подключение открыто, иначе Ложь
#### Описание метода:
Возвращает текущее состояние соединения с устройством.
#### Пример:
```
СоединениеОткрыто = Соединение.Открыто();
```
-----------
#### Название метода:
Записать (Write)
#### Параметры метода:
Текст (строка) - строка, передаваемые на устройство.
#### Возвращаемое значение:
Нет
#### Описание метода:
Синхронно отправляет данные на устройство. К переданной строке метод добавляет знаки перевода каретки и переноса строки.
Может вызывать исключение.
#### Пример:
```
Соединение.Записать("{""type"":""Ping""}");
```
-----------
#### Название метода:
Прочитать (Read)
#### Параметры метода:
ЕстьТокенEnd (булево) - флаг для проверки END токена в сообщении
#### Возвращаемое значение:
Текст (строка) - данные, принятые с удалённого устройства.
#### Описание метода:
Выполняет синхронное чтение данных из потока устройства. Может вызывать исключение.
#### Пример:
```
Ответ = Соединение.Прочитать();
```
-----------
#### Название метода:
Закрыть (Close)
#### Параметры метода:
Нет
#### Возвращаемое значение:
Нет
#### Описание метода:
Выполняет закрытие подключения. Перед закрытием необходимо проверять подключение на активность с помощью метода "Открыто". Может вызывать исключение.
#### Пример:
```
Соединение.Закрыть();
```
