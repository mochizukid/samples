HelloWorldModule = null;  // Global application object.
statusText = 'NO-STATUS';

function moduleDidLoad() {
    HelloWorldModule = document.getElementById('hello_world');
    updateStatus('SUCCESS');

    HelloWorldModule.postMessage('hello');
}

function handleMessage(message_event) {
    alert(message_event.data);
}

function pageDidLoad() {
    if (HelloWorldModule == null) {
        updateStatus('LOADING...');
    } else {
        updateStatus();
    }
}

function updateStatus(opt_message) {
    if (opt_message)
        statusText = opt_message;
    var statusField = document.getElementById('status_field');
    if (statusField) {
        statusField.innerHTML = statusText;
    }
}
