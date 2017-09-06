import React, { Component } from 'react';
import { Modal, Glyphicon, Button} from 'react-bootstrap';

class ErrorModal extends Component {
  handleClose = () => {
    this.props.onClose();
  }

  render() {
    return (
      <Modal show={this.props.show} onHide={() => this.handleClose()} backdrop={false}>
        <Modal.Header closeButton>
          <Modal.Title><Glyphicon glyph="alert" /> Error</Modal.Title>
        </Modal.Header>

        <Modal.Body>
          {this.props.errorMessage}
        </Modal.Body>

        <Modal.Footer>
          <Button onClick={() => this.handleClose()}>Close</Button>
        </Modal.Footer>
      </Modal>
    );
  }
}

export default ErrorModal;
